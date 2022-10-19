#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>

using namespace std;

int main() {
    string s;
    int n;
    cin >> n;
    cin >> s;
    
    for(int i = 0; i < s.size(); i++) {
        vector<int> arr(28, 0);
        for(int j = i; j < s.size(); j++) {
            double len = j - i + 1.0;
            arr[s[j] - 'a']++;
            bool check = true;
            for(int k = 0; k < arr.size(); k++) {
                if(arr[k] * 1.0 > len / 2) {
                    check = false;
                }
            }
            if(check) {
                cout << "YES" << endl;
                for(int start = i; start <= j; start++) {
                    cout << s[start];
                }
                return 0;
            }
        }
    }
    cout << "NO";
    return 0;
}