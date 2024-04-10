#include <iostream>
#include<string.h>
using namespace std;
#include <iostream>
#include <stdio.h>
#include <ctype.h>
int main()
{
    string word;
    cin >> word;
    int counter = 0;
    for(int i = 0; i<word.length(); i++){
        if(isupper(word[i])){
            counter+=1;
        }
        if(islower(word[i])){

        }


    }
    if(counter==word.length()||(islower(word[0])&&counter==word.length()-1)){
    for(int i = 0; i<word.length(); i++){
        if(isupper(word[i])){
            putchar(tolower(word[i]));
        }
        if(islower(word[i])){
            putchar(toupper(word[i]));
        }


    }
    }
    else{
        cout<<word;
    }
}