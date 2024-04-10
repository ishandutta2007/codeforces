#include<iostream>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;

int main(){
    ll n,m;
    cin >> n >> m;
    char a;
    for(int i =0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin >> a;
            if(a=='.'){
                if((i+j)%2==0)cout << "B";
                else cout << "W";
            } else {
                cout << "-";
            }
        }
        cout << endl;

    }
    return 0;
}