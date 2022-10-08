#include <iostream>
#include <cstdio>
#include <string>

using namespace std;
struct asd{
    string s;
};

asd a[10000];
string s1, s, s2;
int uk = 0;


int main(){
   int n, t, i, ii;
    cin >> t;
    for (ii = 0; ii < t; ii++){
        cin >> s1;
        if (s1 == "pwd"){
            printf("%s", "/");
            for (i = 0; i < uk; i++)
                cout << a[i].s << "/";
            printf("\n");           
        }
        if (s1 == "cd"){
            cin >> s;
            n = s.length();
            i = 0;
            if (s[0] == '/'){
                uk = 0;
                i = 1;
            }
            while (i < n){
                s2 = "";
                for (; i < n && s[i] != '/'; i++)
                    s2 += s[i];
                if (s2 == "..")
                    uk--;
                else
                    a[uk++].s = s2;
                i++;
            }
        }

    }


    return 0;
}