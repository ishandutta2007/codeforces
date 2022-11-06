#include <iostream>
#include <cstdio>

using namespace std;

long n,i,j;
string a[8] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
char s[20];
int no;

int main()
{
    scanf("%ld\n",&n);
    scanf("%s",s);

    for(i=0;i<=7;i++){
        if(a[i].size() == n){
            no = 0;
            for(j=0;j<n;j++){
                if((s[j] != '.')&&(s[j] != a[i][j])) {no=1;break;}
            }
            if(no == 0){
                cout << a[i] ;
                return 0;
            }
        }
    }

    return 0;
}