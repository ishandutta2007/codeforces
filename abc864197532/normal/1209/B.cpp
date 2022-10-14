#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 


int main () {
    int n;
    string s;
    cin >> n >> s;
    int nums[n],now=0,maxx=0,aa[n],bb[n];
    fop (i,0,n) {
        nums[i]=s[i]-'0';
        now+=s[i]-'0';
        maxx=max(maxx,now);
    }
    fop (i,0,n) cin >> aa[i] >> bb[i];
    fop (i,1,2520) {
        fop (j,0,n) {
            if (i>=bb[j] && i%aa[j]==bb[j]%aa[j]) {
                if (nums[j]==0) {
                    nums[j]=1;
                    now++;
                } else {
                    nums[j]=0;
                    now--;
                }
            }
        }
        maxx=max(maxx,now);
    }
    cout << maxx << endl;
}