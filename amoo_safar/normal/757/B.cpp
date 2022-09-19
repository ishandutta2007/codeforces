#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld Pi = 3.14159265359;

const long MOD = (long)1e9 + 7;
ll const MAXN = (ll)1e6+10;

bool isPrime(int num) {
    if (num <= 3) {
        return num > 1;
    } else if (num % 2 == 0 || num % 3 == 0) {
        return false;
    } else {
        for (int i = 5; i * i <= num; i += 6) {
            if (num % i == 0 || num % (i + 2) == 0) {
                return false;
            }
        }
        return true;
    }
}

ll pr[100000];

ll a[100000];

int main(){
    ios::sync_with_stdio(false);//cin.tie(0);cout.tie(0);
    ll n,ma =1;
    cin >> n;
    for(int i =0;i<n;i++)cin >> a[i];
    for(int i =0;i<n;i++){
        for(int j = 1;j*j<=a[i];j++){
            if(j*j == a[i]){
                pr[j-1]++;
            }else{
                if(a[i]%j==0){
                    pr[j-1]++;
                    pr[a[i]/j-1]++;
                }
            }
        }
    }
    //cout << ma;
    for(int i =1;i<100000;i++){
        ma = max(ma,pr[i]);
        //cout << pr[i] << endl;
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