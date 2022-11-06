#include <stdio.h>

char arr1[21];
char arr2[21];

int main()
{
    int s=0,i;
    scanf("%s%s",arr1,arr2);
    for(i=0;arr1[i];i+=2)
    {
        if(arr1[i]!=arr2[i])
        {
            if(arr1[i]=='('&&arr2[i]=='8'||arr1[i]=='8'&&arr2[i]=='['||arr1[i]=='['&&arr2[i]=='(')
                s++;
            else
                s--;
        }
    }
    if(s!=0)
        printf("TEAM %d WINS",s>0?1:2);
    else
        printf("TIE");
    return 0;
}