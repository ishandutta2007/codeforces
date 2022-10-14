#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 

/*int mex(vector <int> nums) {
    sort(nums.begin(),nums.end());
    nums.resize(unique(nums.begin(),nums.end())-nums.begin());
    int ans=0;
    fop (i,0,nums.size()) {
        if (nums[i]==ans) ans++;
        else return ans;
    }
}


int nums[101][101];

int find(int n,int k) {
    if (nums[n][k]!=-1) return nums[n][k];
    vector <int> aa;
    if (n>=1) aa.pb(find(n-1,k));
    if (n>=2) aa.pb(find(n-2,k));
    if (n>=k) aa.pb(find(n-k,k));
    return nums[n][k] = mex(aa);
}*/





int main () {
    int n;
    cin >> n;
    vector <int> nums[n];
    fop (i,0,n*n) {
        int k=i%(2*n);
        if (k<n) nums[k].pb(i+1);
        else nums[2*n-1-k].pb(i+1);
    }
    fop (i,0,n) {
        fop (j,0,nums[i].size()) {
            cout << nums[i][j] << ' ';
        }
        cout << endl;
    }
}