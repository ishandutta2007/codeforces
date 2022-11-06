#include <iostream>

using namespace std;

#define maxN 110

long n,i,j,a[maxN][maxN];
char s[maxN];

int main()
{
    cin >> n ;
    cin.getline(s,5);
    for(i=1;i<=n;i++){
        cin.getline(s+1,sizeof(s)-1);
        for(j=1;j<=n;j++){
            if(s[j] == 'o'){
                a[i-1][j]++;
                a[i][j-1]++;
                a[i+1][j]++;
                a[i][j+1]++;
            }
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++)
        if(a[i][j] % 2){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}