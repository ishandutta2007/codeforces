#include <iostream>
#include <string.h>
using namespace std;

int main()
{
int n;
bool d = false;
int t;
int a = 0;
string s;
cin >> n >> t >> s;
for(int j = 0; j <= t; j++){
    for(int i = a; i < n-1; i++){
        if(s[i]=='B'&&s[i+1]=='G'){
            if(j!=t){
            s[i] = 'G';
            s[i+1] = 'B';
            i++;
            }
            else{
                cout << s;
                return 0;
            }

        }
    }
}
cout<<s;



}