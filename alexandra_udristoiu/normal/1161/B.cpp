#include<iostream>
#include<algorithm>
#define x first
#define y second
using namespace std;
int n, m, i, j;
pair<int, int> v[200005], p;
int cautbin(pair<int, int> p){
    int st = 1, dr = m, mid;
    while(st <= dr){
        mid = (st + dr) / 2;
        if(v[mid] == p){
            return 1;
        }
        if(v[mid] < p){
            st = mid + 1;
        }
        else{
            dr = mid - 1;
        }
    }
    return 0;
}
int main(){
    cin>> n >> m;
    for(i = 1; i <= m; i++){
        cin>> v[i].x >> v[i].y;
        v[i].x--;
        v[i].y--;
        if(v[i].y < v[i].x){
            swap(v[i].x, v[i].y);
        }
    }
    sort(v + 1, v + m + 1);
    for(i = 1; i < n; i++){
        if(n % i == 0){
            for(j = 1; j <= m; j++){
                p.x = (v[j].x + i) % n;
                p.y = (v[j].y + i) % n;
                if(p.x > p.y){
                    swap(p.x, p.y);
                }
                if(cautbin(p) == 0){
                    break;
                }
            }
            if(j == m + 1){
                cout<<"Yes";
                return 0;
            }
        }
    }
    cout<<"No";
}