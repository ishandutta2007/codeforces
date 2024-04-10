#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <cstdio>
using namespace std;

typedef pair<int,int> ii;
map<string, ii > FS;
const ii FileNULL = ii(0, 0);
int main()
{
        string str;
        while (cin >> str)
        {
                int newFolder = 0, newFile = 1;
                int pos;
                while ((pos = str.find_last_of('\\')) != 2)
                {
                        str = str.substr(0, pos);
                        bool flag = FS[str] == FileNULL;
                        FS[str].first += newFolder;
                        FS[str].second += newFile;
                        if (flag)
                                newFolder++;
                }
        }
        int maxSubfolder = 0, maxFile = 0;
        for (map<string, ii>::iterator iter = FS.begin(); iter != FS.end(); iter++)
        {
                if (iter->second.first > maxSubfolder) maxSubfolder = iter->second.first;
                if (iter->second.second > maxFile) maxFile = iter->second.second;
        }
        cout << maxSubfolder << " " << maxFile << endl;
}//pozwgg