#include <bits/stdc++.h>
#include <math.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const long MOD = (long)1e9 + 7;
ll const MAXN = 1000000;

stack<ll> s;
stack<ll> t;

int main(){
    ll n, a;
    cin >> n;
    ll m = 0;
    ll out = 0;
    ll g;
    for(int i =0;i<n;i++){
        cin >> a;
        if(a > m){
            m = a;
            s.empty();
            s.push(a);
            t.push(0);
        }else{
            g = 0;
            while(s.top() < a){
                s.pop();
                g = max(t.top(), g);
                t.pop();
            }
            out = max(out, g + 1);
            s.push(a);
            t.push(g+1);
        }
    }
    cout << out;
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