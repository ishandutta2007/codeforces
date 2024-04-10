#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();
    int n,k;
    cin >> n >> k;
    int h[n];
    int imin = -1,imax = -1;
    for (int i = 0; i < n; ++i){
        int x;
        cin >> x;
        if (imin == -1 || imin > x){
            imin = x;
        }
        if (x > imax){
            imax = x;
        }
        h[i] = x;
    }
    sort(h, h + n);
    int kol = 0;
    for (int j = imax; j > imin; --j){
        int s = 0;
        bool f = false;
        while (s <= k && j > imin){
            int l = -1;
            int r = n;
            while (r - l > 1){
                int m = (r + l) / 2;
                if (h[m] < j){
                    l = m;
                }
                else{
                    r = m;
                }
            }
            s += (n - r);
            j -= 1;
            f = true;
        }
        kol++;
        if (f && s > k)
          j += 1;
        j += 1;
    }
    cout<<kol<<endl;
    return 0;
}