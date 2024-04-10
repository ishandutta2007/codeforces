#include <stdio.h>

int main() {
    char s[256];
    scanf("%s", s);
    char* p = s;
    int nc = 4, dig = 0, hig = 0, low = 0;
    while(char c = *p) {
        nc--;
        if (c >= 'a' && c <= 'z') low = true;
        if (c >= 'A' && c <= 'Z') hig = true;
        if (c >= '0' && c <= '9') dig = true;
        p++;
    }
    
    if (low && hig && dig && nc < 0)
         puts("Correct");
    else
         puts("Too weak");
    return 0;
}