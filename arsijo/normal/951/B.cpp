#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
typedef long double ld;

const int MAX = 51;
int ar[MAX][MAX];
int n, m;

vector<pair<pair<int, int>, pair<int, int> > > v;

void add(int x, int y, int xx, int yy){
    v.push_back(make_pair(make_pair(x, y), make_pair(x + xx, y + yy)));
    assert(ar[x][y]);
    assert(ar[x + xx][y + yy] == 0);
    swap(ar[x][y], ar[x + xx][y + yy]);
}

void _left(int x, int y){
    add(x, y, 0, -1);
}


void _right(int x, int y){
    add(x, y, 0, +1);
}

void _down(int x, int y){
    add(x, y, +1, 0);
}

void _up(int x, int y){
    add(x, y, -1, 0);
}

void make_right(int &x, int &y){
    while(y < n && ar[x][y + 1] == 0){
        _right(x, y);
        y++;
    }
}

void make_down(int &x, int &y){
    while(y < n && ar[x][y + 1] == 0){
        _right(x, y);
        y++;
    }
}

void make_left(int &x, int &y){
    while(y > 1 && ar[x][y - 1] == 0){
        _left(x, y);
        y++;
    }
}

void make_free_right(int x, int y){
    if(ar[x][y]){
        make_free_right(x, y + 1);
        _right(x, y);
    }
}


int has_to_be[MAX][MAX];
int X[MAX], Y[MAX];
void make_godno(int x){
    deque<int> d;
    for(int i = 1; i <= n; i++){
        if(ar[x][i]){
            d.push_back(i);
        }
    }
    while(!d.empty()){
        int y = d.front();
        int col = ar[x][y];
        if(Y[col] <= y){
            while(y > Y[col]){
                _left(x, y);
                y--;
            }
            d.pop_front();
        }else{
            y = d.back();
            col = ar[x][y];
            assert(y<= Y[col]);
            while(y < Y[col]){
                _right(x, y);
                y++;
            }
            d.pop_back();
        }
    }
}

set<pair<int, int> > s;

void get(int &x, int &y){
    while(true){
        x = rand() % n + 1;
        y = rand() % n + 1;
        if(s.find(make_pair(x, y)) == s.end()){
            s.insert(make_pair(x, y));
            return;
        }
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);
    cout << fixed;
    srand(time(0));
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    cin >> n >> m;
    if(n == 1){
        cout << 0 << endl;
        return 0;
    }
    for(int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;
        ar[x][y] = i;
    }
    s.clear();
    for(int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;
        X[i] = x;
        Y[i] = y;
        has_to_be[x][y] = i;
    }
    vector<int> v;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(has_to_be[i][j]){
                v.push_back(has_to_be[i][j]);
            }
        }
    }
    for(int j = n; j; j--){
        if(ar[n][j]){
            int x = n, y = j;
            make_right(x, y);
        }
    }
    for(int j = 1; j <= n; j++){
        if(ar[n - 1][j]){
            int x = n - 1, y = j;
            while(ar[x + 1][y]){
                _left(x, y);
                y--;
            }
            _down(x, y);
            x++;
            make_right(x, y);
        }
    }
    int t = 0;
    for(int i = 1; i <= n; i++){
        if(ar[n][i]){
            t++;
        }
    }
    for(int i = 1; i <= m; i++){
        int val = v[i - 1];
        int z = i + (n - m);
        for(int j = 1; j <= n; j++){
            if(ar[n][j] == val){
                int x = n;
                int y = j;
                _up(x, y);
                x--;
                while(y > z){
                    _left(x, y);
                    y--;
                }
                if(ar[n][y]){
                    make_free_right(n, y);
                }
                _down(x, y);
            }
        }
    }
    for(int i = n - 2; i >= 1; i--){
        for(int j = n; j; j--){
            if(ar[i][j]){
                int ind = 0;
                for(int z = 1; z <= m; z++){
                    if(v[z - 1] == ar[i][j]){
                        ind = z + (n - m);
                        break;
                    }
                }
                int x = i;
                int y = j;
                while(x < n - 1){
                    _down(x, y);
                    x++;
                }
                while(ind > y){
                    _right(x, y);
                    y++;
                }
                while(ind < y){
                    _left(x, y);
                    y--;
                }
                _down(x, y);
            }
        }
    }
    for(int i = 1; i + 2 <= n; i++){
        for(int j = 1; j <= n; j++){
            if(has_to_be[i][j]){
                int x = n;
                int y = -1;
                for(int z = 1; z <= n; z++){
                    if(ar[n][z] == has_to_be[i][j]){
                        y = z;
                        break;
                    }
                }
                assert(y != -1);
                _up(x, y);
                x--;
                while(y < j){
                    _right(x, y);
                    y++;
                }
                while(j < y){
                    _left(x, y);
                    y--;
                }
                while(i < x){
                    _up(x, y);
                    x--;
                }
            }
        }
    }

    for(int j = 1; j <= n; j++){
        if(has_to_be[n - 1][j]){
            int x = n;
            int y = -1;
            for(int z = 1; z <= n; z++){
                if(ar[n][z] == has_to_be[n - 1][j]){
                    y = z;
                    break;
                }
            }
            assert(y != -1);
            _up(x, y);
        }
    }
    make_godno(n - 1);
    make_godno(n);
    cout << ::v.size() << endl;
    for(auto a : ::v){
        cout << a.first.first << " " << a.first.second << " " << a.second.first << " " << a.second.second << endl;
    }
}