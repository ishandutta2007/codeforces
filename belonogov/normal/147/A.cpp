#include <iostream>
#include <string>
#include <cstdio>

using namespace std;
string s;

int main()
{
   int n, i;
    bool check = 0;
    getline(cin, s);
    n = s.length();
    for (i = 0; i < n; i++){
        if (s[i] >= 'a' && s[i] <= 'z'){
            if (check){
                printf(" ");
                check = 0;
            }
            cout << s[i];
          //  printf("%ch", s[i]);
            if (i + 1 < n && s[i + 1] == ' ')
                check = 1;
            continue;
        }
        if (s[i] != ' '){
            cout << s[i];
          //  printf("%ch", s[i]);
            check = 1;
        }

    }
    return 0;
}