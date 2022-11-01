#include <iostream>
#include <string.h>
using namespace std;

char s[200];
char cur = s[0];
//cout << cur << endl;
int qua;
int ans;


int main()
{
    cin >> s;
    qua = 1;
    ans = 0;
    //cout << ans << endl;
    int leng = strlen(s);
    //cout << leng << endl;
    for (int i=0; i<leng; i++){
        if (s[i]!=cur){
            cur = s[i];
            qua = 1;}
        else
            qua++;
        //cout << qua << ans << endl;
        if (qua >=7)
            ans = 1;
    }
    if (ans == 1)
       cout << "YES";
    else
       cout << "NO";
    return 0;
}