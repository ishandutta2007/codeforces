//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define ms(x) memset(x, 0, sizeof(x));
#define input freopen("input.txt", "r", stdin);
#define output freopen("output.txt", "w", stdout);
#define ll long long
#define ld long double
#define sqr(a) ( (a) * (a) )
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const ld E = 1e-9;
const int MAX = 1e9;


int main() {

    int n, k, p, x, y;
    cin >> n >> k >> p >> x >> y;

    int g = 0, sum = 0;
    for(int i = 0; i < k; i++){
        int a;
        cin >> a;
        sum += a;
        if(a >= y)
            g++;
    }

    vector<int> vec;

    for(int i = g; i <= n / 2; i++){
        k++;
        sum += y;
        vec.push_back(y);
    }

    for(int i = k; i < n; i++){
        sum++;
        vec.push_back(1);
    }

    if(sum > x || k > n){
        cout << -1;
    }else{
        for(int i = 0; i < vec.size(); i++)
            cout << vec[i] << " ";
    }


}