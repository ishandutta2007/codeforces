#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, n1;
    cin >> n;
    n1 = n;
    int res = 1;
    int ans = 0;
    int ind = 2;
    map < int, int > m;
    int max_st = 0;
    bool f = true;
    while (ind * ind <= n){
        if (n % ind == 0){
            n /= ind;
            if (m.find(ind) == m.end()){
                m[ind] = 1;
                f = false;
                max_st = max(max_st, 1);
            }
            else{
                m[ind] += 1;
                max_st = max(max_st, m[ind]);
            }
            ind -=1;
        }
        ind++;
    }
    if (n > 1){
        if (m.find(n) == m.end()){
            m[n] = 1;
            max_st = max(max_st, m[n]);
        }
        else{
            m[n] += 1;
            max_st = max(max_st, m[n]);
        }
    }
    if (f){
        cout << n1 << " " << 0 << endl;
        return 0;
    }
    int pr = 1;
    f = true;
    for (auto key : m){
        if (key.second != max_st){
            f = false;
            //cout << key.first << " " << key.second << endl;
        }
        pr *= key.first;
    }
    int rt = 1;
    int it = 1;
    while (rt < max_st){
        rt *= 2;
        it++;
    }
    if (rt == max_st){
        if (f)
            cout << pr << " " << it - 1 << endl;
        else
            cout << pr << " " << it << endl;
    }
    else{
        cout << pr << " " << it << endl;
    }
}