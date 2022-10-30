#include <bits/stdc++.h>

using namespace std;

int n, t, tt, db[303], maxi=0;
vector<int> v;

int longestIncreasingSubsequence(vector<int>& vec) {
  vector<int> lis(vec.size(), -1);
  int lis_max = 0;
  for (int i = 0; i < vec.size(); ++i) {
    int lo = 0;
    int hi = lis_max;
    while (lo < hi) {
      int mid =(lo+hi)/2;
      if (vec[i] > lis[mid])
        lo=mid+1;
      else
        hi=mid;
    }
    if (lo >= lis_max)
      ++lis_max;
    lis[lo] = vec[i];
  }
  return lis_max;
}

int main()
{
    cin >> n >> t;
    if(t>n) {
        tt=t-n;
        t=n;
    }
    v.resize(n*t);
    for(int i=0;i<n;i++) {
        int be;
        cin >> be;
        db[be]++;
        if(db[be]>maxi) maxi++;
        for(int j=0;j<t;j++) {
            v[i+j*n]=j*300+i+be*300*300;
        }
    }
    int ki=longestIncreasingSubsequence(v);
    cout << maxi*tt+ki << endl;
    return 0;
}