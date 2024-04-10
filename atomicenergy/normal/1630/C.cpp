

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>


using namespace std;

typedef long long ll;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

        int n;
        cin >> n;
        map<int, int> lst;
        vector<int> v;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            v.push_back(x);
            lst[x] = i;
        }
        int a = -1;
        int c = -1;
        int b = -1;
        for (int i = 0; i < n; i++) {
            if (i > b) {
                a+=2;
                c = i;
                b = max(i + 1, lst[v[i]]);
            }
            else if (i > c) {
                a++;
                c = b;
                b = max(b+1, lst[v[i]]);
            }
            else {
                b = max(b, lst[v[i]]);
            }
        }

        cout << n-a << endl;

    

}