#include <bits/stdc++.h>

using namespace std;

main(){
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    set < int > W = {4, 8, 15, 16, 23, 42};
    vector < int > Q = {4, 8, 15, 16, 23, 42};
    cout << "? 1 2" << endl;
    int x, x1;
    cin >> x;
    vector < int > out;
    cout << "? 3 2" << endl;
    cin >> x1;
    for (auto key : Q){
        if (x % key == 0 && x1 % key == 0){
            if (W.find(x / key) != W.end() && W.find(x1 / key) != W.end() && x / key != key && x1 / key != key && x / key != x1 / key){
                out.push_back(x / key);
                out.push_back(key);
                out.push_back(x1 / key);
            }
        }
    }
    cout << "? 4 5" << endl;
    cin >> x;
    cout << "? 5 6" << endl;
    cin >> x1;
    for (auto key : Q){
        if (x % key == 0 && x1 % key == 0){
            if (W.find(x / key) != W.end() && W.find(x1 / key) != W.end() && x / key != key && x1 / key != key && x / key != x1 / key){
                out.push_back(x / key);
                out.push_back(key);
                out.push_back(x1 / key);
            }
        }
    }
    cout << "! ";
    for (auto key : out) cout << key << " ";
    cout << endl;
    return 0;
}