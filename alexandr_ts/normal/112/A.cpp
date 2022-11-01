#include <iostream>
#include <string.h>

using namespace std;

char small(char ch){
if (ch<'a'){
    //cout<< "small"<<endl;
    ch += ('a' - 'A');
    }
    return ch;
}
int ans = 0;
char s1[100], s2[100];

int main()
{
    cin >> s1;
    cin >> s2;

    for (int i = 0; i<strlen(s1); i++){
        s1[i] = small(s1[i]);
        s2[i] = small(s2[i]);
        //cout << s1[i] << " "<< s2[i]<< endl;
        if ((s1[i]<s2[i]) && (ans == 0))
            ans = -1;
        if ((s1[i]>s2[i]) && (ans == 0))
            ans = 1;
    }
    cout << ans;
    return 0;
}