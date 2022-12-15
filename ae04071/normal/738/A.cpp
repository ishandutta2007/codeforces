#include <stdio.h>
#include <cstring>

int n;
char str[110];
char res[110];

int main()
{
    //freopen("input.txt","r",stdin);
    scanf("%d",&n);
    scanf("%s", str);

    int idx = 0;
    for(int i = 0; i < n; i++) {
        if(str[i] == 'o') {
            if(i + 2 < n && str[i+1] == 'g' && str[i+2] == 'o') {
                res[idx++] = '*';
                res[idx++] = '*';
                res[idx++] = '*';
                i += 3;
                while(i + 1 < n && str[i] == 'g' && str[i+1] == 'o') {
                    i += 2;
                }
                i--;
            }
            else {
                res[idx++] = str[i];
            }
        }
        else
            res[idx++] = str[i];

    }

    printf("%s\n", res);

    return 0;
}