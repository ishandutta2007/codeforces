#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <utility>
#include <algorithm>
#define go(a,b) for(int a=0; a<b; a++)
using namespace std;



int main()
{
    int n;
    string s;
    cin >> n;
    for(int a=0; a<n; a++){
    cin >> s;
    if(s.length()>10){
        cout << s[0] << s.length()-2 << s[s.length()-1] << endl;
    }
    else{
        cout << s << endl;
    }
    }
}