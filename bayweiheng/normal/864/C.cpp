#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <list>
#include <cstring>
#include <queue>
#include <bitset>
#include <set>
#include <stack>
#include <complex>
#include <functional>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<string> vs;

int main() {
    int a,b,f,k;
    cin>>a>>b>>f>>k;
    if (k==1) { //special case
        int longest=max(f,a-f);
        if (b<longest) cout<<-1<<endl;
        else if (b>=a) cout<<0<<endl;
        else cout<<1<<endl;
    } else if (k==2) {
        int longest=max(f,2*(a-f));
        if (b<longest) cout<<-1<<endl;
        else if (b>=2*a) cout<<0<<endl;
        else if (b>=2*a-f) cout<<1<<endl;
        else cout<<2<<endl;
    } else {
        int longest=max(2*f,2*(a-f));
        if (b<longest) cout<<-1<<endl;
        else {
            int ans=0;
            int fuel=b-f;
            int times=k-1;
            for(int i=0;i<times;i++) {
                if (i%2==0) {
                    if (fuel-2*(a-f)<0) {
                        ans++;
                        fuel=b-2*(a-f);
                    } else fuel-=2*(a-f);
                } else {
                    if (fuel-2*f<0) {
                        ans++;
                        fuel=b-2*f;
                    } else fuel-=2*f;
                }
            }
            if (k%2==0 && fuel<f) ans++;
            if (k%2==1 && fuel<a-f) ans++;
            cout<<ans<<endl;
        }
    }
}