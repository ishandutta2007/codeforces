#include <bits/stdc++.h>

using namespace std;

int main(){
    long long l, r, k;
    cin >> l >> r >> k;
    if(r - l <= 10){
        vector<long long> v;
        for(long long i = l; i<=r; i++){
            v.push_back(i);
        }
        int N = (int) (r-l+1);
        long long ans = l;
        vector<long long> out;
        for(int m = 1; m<1<<N; m++){
            if(__builtin_popcount(m) <= k){
                long long temp = 0;
                for(int k = 0; k<N; k++){
                    if((m>>k)&1){
                        temp ^= v[k];
                    }
                }
                if(temp <= ans){
                    ans = temp;
                    out.clear();
                    for(int k = 0; k<N; k++){
                        if((m>>k)&1){
                            out.push_back(v[k]);
                        }
                    }
                }
            }
        }
        cout << ans << endl;
        cout << out.size() << endl;
        for(long long n : out){
            cout << n << " ";
        }
    }
    else if(k == 1){
        cout << l << "\n" << 1 << "\n" << l << endl;
    }
    else if(k == 2){
        l = (l+1)/2*2;
        cout << 1 << "\n" << 2 << "\n" << l << " " << l+1 << endl;
    }
    else if(k == 3){
        long long z = 1, x = 3;
        while(x <= r){
            if(z >= l){
                cout << 0 << "\n" << 3 << "\n";
                cout << x << " " << z << " " << (x^z) << endl;
                return 0;
            }
            x *= 2;
            z *= 2;
            z++;
        }
        l = (l+1)/2*2;
        cout << 1 << "\n" << 2 << "\n" << l << " " << l+1 << endl;
    }
    else{
        l = (l+3)/4*4;
        cout << 0 << "\n" << 4 << "\n" << l << " " << l+1 << " " << l+2 << " " << l+3 << endl;
    }
}