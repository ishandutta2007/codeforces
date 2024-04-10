#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int>>> xy(3, vector<pair<int, int>>());
vector<vector<pair<int, int>>> xy_x(3, vector<pair<int, int>>());
vector<vector<pair<int, int>>> xy_xr(3, vector<pair<int, int>>());
vector<vector<pair<int, int>>> xy_y(3, vector<pair<int, int>>());
vector<vector<pair<int, int>>> xy_yr(3, vector<pair<int, int>>());


int n;
int A[6] = {0, 0, 1, 1, 2, 2};
int B[6] = {1, 2, 0, 2, 0, 1};
int C[6] = {2, 1, 2, 0, 1, 0};
const int inf = 1 << 30;

bool yy(pair<int, int> &lhs, pair<int, int> &rhs){
    return lhs.second < rhs.second;
}

bool yy_r(pair<int, int> &lhs, pair<int, int> &rhs){
    return lhs.second > rhs.second;
}



bool ok(int z){
    int a, b, c, x, y, max_x, max_y, flg, cnt;
    for(int i = 0; i < 6; i++){
        a = A[i];
        b = B[i];
        c = C[i];
        
        
        
        max_x = -inf;
        flg = 0;
        cnt = 0;
        for(auto tmp: xy_x[a]){
            x = tmp.first;
            y = tmp.second;
            if(x >= max_x){
                max_x = x;
                cnt++;
                if(cnt == z){
                    flg++;
                    break;
                }
            }
        }
        cnt = 0;
        max_x++;
        
        for(auto tmp: xy_x[b]){
            x = tmp.first;
            y = tmp.second;
            if(x >= max_x){
                max_x = x;
                cnt++;
                if(cnt == z){
                    flg++;
                    break;
                }
            }
        }
        
        cnt = 0;
        max_x++;
        
        for(auto tmp: xy_x[c]){
            x = tmp.first;
            y = tmp.second;
            if(x >= max_x){
                max_x = x;
                cnt++;
                if(cnt == z){
                    flg++;
                    break;
                }
            }
        }
        
        if(flg == 3) return true;
        
        
        
        max_y = -inf;
        flg = 0;
        cnt = 0;
        for(auto tmp: xy_y[a]){
            x = tmp.first;
            y = tmp.second;
            if(y >= max_y){
                max_y = y;
                cnt++;
                if(cnt == z){
                    flg++;
                    break;
                }
            }
        }
        cnt = 0;
        max_y++;
        
        for(auto tmp: xy_y[b]){
            x = tmp.first;
            y = tmp.second;
            if(y >= max_y){
                max_y = y;
                cnt++;
                if(cnt == z){
                    flg++;
                    break;
                }
            }
        }
        
        cnt = 0;
        max_y++;
        
        for(auto tmp: xy_y[c]){
            x = tmp.first;
            y = tmp.second;
            if(y >= max_y){
                max_y = y;
                cnt++;
                if(cnt == z){
                    flg++;
                    break;
                }
            }
        }
        
        if(flg == 3) return true;
        
        
        
        max_x = -inf;
        flg = 0;
        cnt = 0;
        for(auto tmp: xy_x[a]){
            x = tmp.first;
            y = tmp.second;
            if(x >= max_x){
                max_x = x;
                cnt++;
                if(cnt == z){
                    flg++;
                    break;
                }
            }
        }
        cnt = 0;
        max_x++;
        max_y = -inf;
        
        for(auto tmp: xy_y[b]){
            x = tmp.first;
            y = tmp.second;
            if(x >= max_x && y >= max_y){
                max_y = y;
                cnt++;
                if(cnt == z){
                    flg++;
                    break;
                }
            }
        }
        
        cnt = 0;
        max_y++;
        
        for(auto tmp: xy_y[c]){
            x = tmp.first;
            y = tmp.second;
            if(x >= max_x && y >= max_y){
                max_y = y;
                cnt++;
                if(cnt == z){
                    flg++;
                    break;
                }
            }
        }
        
        if(flg == 3) return true;
        
        
        max_x = inf;
        flg = 0;
        cnt = 0;
        for(auto tmp: xy_xr[a]){
            x = tmp.first;
            y = tmp.second;
            if(x <= max_x){
                max_x = x;
                cnt++;
                if(cnt == z){
                    flg++;
                    break;
                }
            }
        }
        cnt = 0;
        max_x--;
        max_y = -inf;
        
        for(auto tmp: xy_y[b]){
            x = tmp.first;
            y = tmp.second;
            if(x <= max_x && y >= max_y){
                max_y = y;
                cnt++;
                if(cnt == z){
                    flg++;
                    break;
                }
            }
        }
        
        cnt = 0;
        max_y++;
        
        for(auto tmp: xy_y[c]){
            x = tmp.first;
            y = tmp.second;
            if(x <= max_x && y >= max_y){
                max_y = y;
                cnt++;
                if(cnt == z){
                    flg++;
                    break;
                }
            }
        }
        
        if(flg == 3) return true;
        
        
        
        
        max_y = -inf;
        flg = 0;
        cnt = 0;
        for(auto tmp: xy_y[a]){
            x = tmp.first;
            y = tmp.second;
            if(y >= max_y){
                max_y = y;
                cnt++;
                if(cnt == z){
                    flg++;
                    break;
                }
            }
        }
        cnt = 0;
        max_y++;
        max_x = -inf;
        
        for(auto tmp: xy_x[b]){
            x = tmp.first;
            y = tmp.second;
            if(x >= max_x && y >= max_y){
                max_x = x;
                cnt++;
                if(cnt == z){
                    flg++;
                    break;
                }
            }
        }
        
        cnt = 0;
        max_x++;
        
        for(auto tmp: xy_x[c]){
            x = tmp.first;
            y = tmp.second;
            if(x >= max_x && y >= max_y){
                max_x = x;
                cnt++;
                if(cnt == z){
                    flg++;
                    break;
                }
            }
        }
        
        if(flg == 3) return true;
        
        
        
        
        
        max_y = inf;
        flg = 0;
        cnt = 0;
        for(auto tmp: xy_yr[a]){
            x = tmp.first;
            y = tmp.second;
            if(y <= max_y){
                max_y = y;
                cnt++;
                if(cnt == z){
                    flg++;
                    break;
                }
            }
        }
        cnt = 0;
        max_y--;
        max_x = -inf;
        
        for(auto tmp: xy_x[b]){
            x = tmp.first;
            y = tmp.second;
            if(x >= max_x && y <= max_y){
                max_x = x;
                cnt++;
                if(cnt == z){
                    flg++;
                    break;
                }
            }
        }
        
        cnt = 0;
        max_x++;
        
        for(auto tmp: xy_x[c]){
            x = tmp.first;
            y = tmp.second;
            if(x >= max_x && y <= max_y){
                max_x = x;
                cnt++;
                if(cnt == z){
                    flg++;
                    break;
                }
            }
        }
        
        if(flg == 3) return true;
        
        
        
        
    }
    
    return false;
}


int main(void){
    cin >> n;
    int x, y, c;
    for(int i = 0; i < n; i++){
        cin >> x >> y >> c;
        xy[c - 1].push_back({x, y});
    }
    
    for(int i = 0; i < 3; i++){
        sort(xy[i].begin(), xy[i].end());
        xy_x[i] = xy[i];
        sort(xy[i].begin(), xy[i].end(), greater<pair<int, int>>());
        xy_xr[i] = xy[i];
        sort(xy[i].begin(), xy[i].end(), yy);
        xy_y[i] = xy[i];
        sort(xy[i].begin(), xy[i].end(), yy_r);
        xy_yr[i] = xy[i];
    }
    
    
    int l, r, mid;
    l = 1;
    r = n + 1;
    while(r - l > 1){
        mid = (l + r) / 2;
        if(ok(mid)) l = mid;
        else r = mid;
    }
    cout << 3 * l << "\n";
    
}