#include <iostream>
#include <stack>
#include <map>

using namespace std;

map <int, int> mymap;

int main(){
    int n;
    string s;
    cin >> n >> s;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == '2' || s[i] == '3' || s[i] == '5' || s[i] == '7')
            mymap[s[i] - '0'] ++;
        else if (s[i] == '4'){
            mymap[2] += 2;
            mymap[3] ++;
        }
        else if (s[i] == '6'){
            mymap[5] ++;
            mymap[3] ++;
        }
        else if (s[i] == '8'){
            mymap[7] ++;
            mymap[2] += 3;
        }
        else if (s[i] == '9'){
            mymap[7] ++;
            mymap[3] += 2;
            mymap[2] ++;
        }
    }
    for (int i = 9; i > 1; i--){
        while (mymap[i] > 0){
            cout << i;
            mymap[i] --;
        }
    }
}