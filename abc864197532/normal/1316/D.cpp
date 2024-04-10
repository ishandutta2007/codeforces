#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>
#define X first
#define Y second
const int N = 1000;

pii input[N][N];
char ans[N][N];
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
char movee[4] = {'L', 'R', 'U', 'D'};
int n;

void bfs(int x, int y) {
    queue <pii> q;
    q.push({x, y});
    int xx, yy;
    while (q.size()) {
        tie(xx, yy) = q.front(); q.pop();
        fop (i,0,4) {
            int nx = xx + dx[i], ny = yy + dy[i];
            if (0 <= nx and nx < n and 0 <= ny and ny < n and input[nx][ny] == input[x][y] and ans[nx][ny] == ' ') {
                ans[nx][ny] = movee[i];
                q.push({nx, ny});
            }
        }
    }
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	fop (i,0,n) {
	    fop (j,0,n) {
	        cin >> input[i][j].X >> input[i][j].Y;
	        input[i][j].X--;
	        input[i][j].Y--;
	        if (input[i][j].X == i and input[i][j].Y == j) ans[i][j] = 'X';
	        else ans[i][j] = ' ';
	    }
	}
	fop (i,0,n) fop (j,0,n) if (ans[i][j] == 'X') bfs(i, j);
	fop (i,0,n) {
	    fop (j,0,n) {
	        if (input[i][j] == mp(-2, -2) and ans[i][j] == ' ') {
	            int nx = -1, ny = -1, idx = -1;
	            fop (k,0,4) {
	                nx = i + dx[k];
	                ny = j + dy[k];
	                if (nx < 0 or nx >= n or ny < 0 or ny >= n) continue;
	                if (input[nx][ny] == mp(-2, -2)) {
	                    idx = k;
	                    break;
	                }
	            }
	            if (idx == -1) {
    	            cout << "INVALID" << endl;
    	            return 0;
	            }
	            ans[i][j] = movee[idx ^ 1];
	            ans[nx][ny] = movee[idx];
	            bfs(i, j);
	            bfs(nx, ny);
	        } else if (ans[i][j] == ' ') {
	            cout << "INVALID" << endl;
	            return 0;
	        }
	    }
	}
	cout << "VALID" << endl;
	fop (i,0,n) {
	    fop (j,0,n) {
	        cout << ans[i][j];
	    }
	    cout << endl;
	}
}