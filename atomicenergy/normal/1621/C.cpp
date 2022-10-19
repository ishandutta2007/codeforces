

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>


using namespace std;

int guess(int a) {
    cout << "? " << a+1 << endl;
    int x;
    cin >> x;
    return x-1;
}

int main(){
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        vector<int> v(n, -1);
        int i = 0;
        while (i < n) {
            if (v[i] != -1) {
                i++;
                continue;
            }
            int prev = guess(i);
            int first = prev;
            while (true) {
                int a = guess(i);
                v[prev] = a;
                prev = a;
                if (a == first) break;
            }
        }
        cout << "! ";
        for (auto p : v) {
            cout << p+1 << " ";
        }
        cout << endl;
    }



}