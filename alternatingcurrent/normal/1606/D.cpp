#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
void readint(int &x){
	x = 0;
	char c = getchar();
	while(c < '0' || c > '9')
		c = getchar();
	while(c >= '0' && c <= '9')
		x = x * 10 + c - '0', c = getchar();
}
int qmax(int a, int b){
	return (a > b) ? a : b;
}
int qmin(int a, int b){
	return (a < b) ? a : b;
}

int T;
int n, m;
int a[1000100];
pair<int, int> head[1000100], rear[1000100];
int headpreval[1000100], headsufval[1000100];
int rearpreval[1000100], rearsufval[1000100];
// pre max suf min
int headcnt[1000100], rearcnt[1000100];
int cntdiff;

int main(){
	readint(T);
	while(T --> 0){
		readint(n), readint(m);
		rep(i, n * m)
			readint(a[i]);
		rep(i, n){
			head[i] = make_pair(a[i * m], i);
			rear[i] = make_pair(a[i * m + m - 1], i);
		}
		sort(head, head + n), sort(rear, rear + n);
		
		rep(i, n)
			headpreval[i * m] = qmax(i ? headpreval[(i - 1) * m] : 0, a[head[i].second * m]);
		for(int j = 1; j < m; j++)
			rep(i, n)
				headpreval[i * m + j] = qmax(qmax(i ? headpreval[(i - 1) * m + j] : 0, headpreval[i * m + j - 1]), a[head[i].second * m + j]);
		
		for(int i = n - 1; i >= 0; i--)
			headsufval[i * m] = qmin((i < n - 1) ? headsufval[(i + 1) * m] : 0x3f3f3f3f, a[head[i].second * m]);
		for(int j = 1; j < m; j++)
			for(int i = n - 1; i >= 0; i--)
				headsufval[i * m + j] = qmin(qmin((i < n - 1) ? headsufval[(i + 1) * m + j] : 0x3f3f3f3f, headsufval[i * m + j - 1]), a[head[i].second * m + j]);
		
		rep(i, n)
			rearpreval[i * m + m - 1] = qmax(i ? rearpreval[(i - 1) * m + m - 1] : 0, a[rear[i].second * m + m - 1]);
		for(int j = m - 2; j >= 0; j--)
			rep(i, n)
				rearpreval[i * m + j] = qmax(qmax(i ? rearpreval[(i - 1) * m + j] : 0, rearpreval[i * m + j + 1]), a[rear[i].second * m + j]);
		
		for(int i = n - 1; i >= 0; i--)
			rearsufval[i * m + m - 1] = qmin((i < n - 1) ? rearsufval[(i + 1) * m + m - 1] : 0x3f3f3f3f, a[rear[i].second * m + m - 1]);
		for(int j = m - 2; j >= 0; j--)
			for(int i = n - 1; i >= 0; i--)
				rearsufval[i * m + j] = qmin(qmin((i < n - 1) ? rearsufval[(i + 1) * m + j] : 0x3f3f3f3f, rearsufval[i * m + j + 1]), a[rear[i].second * m + j]);
		
//		rep(i, n)
//			cout << head[i].first << "," << head[i].second << "  ";
//		cout << endl;
//		rep(i, n){
//			rep(j, m)
//				cout << headpreval[i * m + j] << " ";
//			cout << endl;
//		}
//		rep(i, n){
//			rep(j, m)
//				cout << headsufval[i * m + j] << " ";
//			cout << endl;
//		}
//		rep(i, n)
//			cout << rear[i].first << "," << rear[i].second << "  ";
//		cout << endl;
//		rep(i, n){
//			rep(j, m)
//				cout << rearpreval[i * m + j] << " ";
//			cout << endl;
//		}
//		rep(i, n){
//			rep(j, m)
//				cout << rearsufval[i * m + j] << " ";
//			cout << endl;
//		}
		cntdiff = 0;
		rep(i, n)
			headcnt[i] = rearcnt[i] = 0;
		bool ok = 0;
		string s;
		rep(i, n)
			s += 'R';
		rep(i, n - 1){
			s[head[i].second] = 'B';
			headcnt[head[i].second]++;
			if(rearcnt[head[i].second])
				cntdiff--;
			else
				cntdiff++;
			rearcnt[rear[n - i - 1].second]++;
			if(headcnt[rear[n - i - 1].second])
				cntdiff--;
			else
				cntdiff++;
//			cout << i << ": " << cntdiff << endl;
			if(cntdiff == 0){
				int lb = 0, ub = m;
				while(lb <= ub){
					int mid = (lb + ub) >> 1;
					int pos = qmin(mid, m - 1);
					if(headpreval[i * m + pos] < headsufval[(i + 1) * m + pos])
						lb = mid + 1;
					else
						ub = mid - 1;
				}
				int r = ub;
				lb = 0, ub = m;
				while(lb <= ub){
					int mid = (lb + ub) >> 1;
					int pos = qmin(mid, m - 1);
//					cout << n - i - 1 << " " << pos << ": " << rearpreval[(n - i - 2) * m + pos] << " " << rearsufval[(n - i - 1) * m + pos] << endl;
					if(rearpreval[(n - i - 2) * m + pos] < rearsufval[(n - i - 1) * m + pos])
						ub = mid - 1;
					else
						lb = mid + 1;
				}
				int l = lb;
//				cout << i << ": " << l << " " << r << endl;
				if(l <= r + 1){
					ok = 1;
					cout << "YES" << endl;
					cout << s << " " << r + 1 << endl;
					break;
				}
			}
		}
		if(!ok)
			cout << "NO" << endl;
	}
	return 0;
}