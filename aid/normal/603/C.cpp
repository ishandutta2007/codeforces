#include <iostream>

using namespace std;

int getGr(int a) {
    if(a == 1)
        return 1;
    if(a == 2)
        return 0;
    if(a == 3)
        return 1;
    if(a == 4)
        return 2;
    if(a & 1)
        return 0;
    int res = 1;
    if(res == getGr(a / 2))
        res++;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    k = (k & 1);
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if(k)
            ans ^= getGr(a);
        else {
            if(a == 1)
                ans ^= 1;
            else if(a == 2)
                ans ^= 2;
            else
                ans ^= ((a & 1) ^ 1);
        }
    }
    if(ans)
        cout << "Kevin\n";
    else
        cout << "Nicky\n";
    return 0;
}