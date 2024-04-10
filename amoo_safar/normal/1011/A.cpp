#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const long MOD = (long)1e9 + 7;
ll const MAXN = 100001;


char a[50];
int main(){
    ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    ll n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    for(int i =0;i<n;i++)a[i]= s[i];;
    sort(a,a+n);
    char l = 'a' - 2;
    ll po= 0;
    ll out=0;
    while(po < n and k > 0){
        if(a[po] - l >= 2){
            l = a[po];
            k --;
            out += ((ll)a[po]);
            out -= ((ll)'a');
            out ++;
        }
        po++;
    }
    if(k > 0)cout << -1;
    else cout << out;
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