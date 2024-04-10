#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <fstream>
#include <string.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define first fs
#define second sc

using namespace std;

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);


    int n;
    cin >> n;

    vector<int> p(n);
    for (int i = 0; i < n; ++i) 
        cin >> p[i];

    string s;
    getline(cin, s);

    for (int i = 0; i < n; ++i) {
        string s;
        getline(cin, s);

        int cur = 0;
        for (int j = 0; j < sz(s); ++j)
            if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u' || s[j] == 'y')
                ++cur;

        if (cur != p[i]) {
            cout << "NO" << endl;
            return 0;
        }
        
    }

    cout << "YES" << endl;


}