#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld Pi = 3.14159265359;

const long MOD = (long)1e9 + 7;
ll const MAXN = 400010;

ll a[2][300000];
ll ps[300000];
ll psd[300000];
ll psu[300000];
int main(){
    ios::sync_with_stdio(false);//cin.tie(0);cout.tie(0);
    ll n;
    cin >> n;
    for(int i = 0 ;i<2;i++){
        for(int j =0;j<n;j++)cin >> a[i][j];
    }
    ps[n-1] = a[0][n-1] + a[1][n-1];
    psd[n-1] = 2*a[0][n-1] + a[1][n-1];
    psu[n-1] = a[0][n-1] + 2*a[1][n-1];
    for(int i = n-2;i>=0;i--){
        ps[i] = ps[i + 1]+a[0][i]+a[1][i];
        psu[i] = psu[i+1] + ps[i + 1] + a[0][i] + 2*(n-i)*a[1][i];
        psd[i] = psd[i+1] + ps[i + 1] + a[1][i] + 2*(n-i)*a[0][i];
    }
    /*for(int i =0;i<n;i++)cout << ps[i] << " ";
    cout << endl;
    for(int i =0;i<n;i++)cout << psd[i] << " ";
    cout << endl;
    for(int i =0;i<n;i++)cout << psu[i] << " ";
    cout << endl;*/
    ll ma = 0;
    ll eat = 0;
    ll mi = 0;
    ll ge;
    for(int i =0;i<n;i++){
        if(i!=0){
            if(i%2==0){
                eat  = eat + a[0][i-1]*(mi+1);
                eat  = eat + a[1][i-1]*(mi);
            }
            if(i%2==1){
                eat  = eat + a[1][i-1]*(mi+1);
                eat  = eat + a[0][i-1]*(mi);
            }
            mi +=2;
        }
        //cout << eat << endl;
        if(i%2==0){
            ge = psu[i];
        }else {
            ge = psd[i];
        }
        ma = max(ma , eat + ge + (mi-1)*ps[i]);
    }
    cout << ma;
    return 0;
}



/*
           _____           ______              ______        _______________           _______________
          /     \         |      \            /      |      /               \         /               \
         /       \        |       \          /       |     /                 \       /                 \
        /   ___   \       |   |\   \        /   /|   |    /    ___________    \     /    ___________    \
       /   /   \   \      |   | \   \      /   / |   |   |    /           \    |   |    /           \    |
      /   /_____\   \     |   |  \   \    /   /  |   |   |   |            |    |   |   |            |    |
     /               \    |   |   \   \  /   /   |   |   |    \___________/    |   |    \___________/    |
    /    _________    \   |   |    \   \/   /    |   |    \                   /     \                   /
   /    /         \    \  |   |     \      /     |   |     \                 /       \                 /
  /____/           \____\ |___|      \____/      |___|      \_______________/         \_______________/

*/