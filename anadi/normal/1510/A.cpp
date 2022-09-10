#include <bits/stdc++.h>
using namespace std;

const int N = 101;
char str[N];

char *ptr;

struct atom
{
    virtual void init() = 0;
    virtual void read(bool one = false) = 0;
    
    void resize()
    {    
        tab.resize(rows, vector<char>(cols, ' '));
    }
    
    void fill_hor(int row, int col_a, int col_b, char c)
    {
        for(int i = col_a; i <= col_b; i++)
            tab[row][i] = c;
    }
    
    void fill_ver(int row_a, int row_b, int col, char c)
    {
        for(int i = row_a; i <= row_b; i++)
            tab[i][col] = c;
    }
    
    void insert(atom *a, int r, int c)
    {
        for(int i = 0; i < a->rows; i++)
            for(int j = 0; j < a->cols; j++)
                tab[r+i][c+j] = a->tab[i][j];
    }
    
    void insert(string str, int r, int c)
    {
        for(int i = 0; i < str.size(); i++)
            tab[r][c+i] = str[i];
    }
    
    void rect(int row_a, int row_b, int col_a, int col_b)
    {
        fill_hor(row_a, col_a, col_b, '-');
        fill_hor(row_b, col_a, col_b, '-');
        fill_ver(row_a, row_b, col_a, '|');
        fill_ver(row_a, row_b, col_b, '|');
        tab[row_a][col_a] = tab[row_b][col_a] = tab[row_a][col_b] = tab[row_b][col_b] = '+';
    }
    
    int rows, cols;
    vector<vector<char>> tab;
};

atom *read_atom(bool one = false);

struct term : atom
{
    vector<atom*> atoms;
    
    void read(bool one = false)
    {
        while(ptr >= str && *ptr != '|' && *ptr != '(')
            atoms.push_back(read_atom());
        reverse(atoms.begin(), atoms.end());
    }
    
    void init()
    {
        fprintf(stderr, "init term\n");
        cols = -2;
        rows = 0;
        for(auto a: atoms)
        {
            a->init();
            cols += a->cols + 2;
            rows = max(rows, a->rows);
        }
        resize();
        int p = 0;
        for(auto a: atoms)
        {
            if(p != 0)
            {
                tab[1][p++] = '-';
                tab[1][p++] = '>';
            }
            insert(a, 0, p);
            p += a->cols;
        }
        fprintf(stderr, "done term\n");
    }
};

struct expr : atom
{
    vector<term*> terms;
    
    void read(bool one = false)
    {
        while(true)
        {
            auto t = new term;
            t->read();
            terms.push_back(t);
            if(ptr < str || *ptr == '(')
                break;
            assert(*ptr == '|');
            ptr--;
        }
        reverse(terms.begin(), terms.end());
    }
    
    void init()
    {
        fprintf(stderr, "init expr\n");
        for(auto t: terms) 
            t->init();
        if(terms.size() == 1)
        {
            rows = terms[0]->rows;
            cols = terms[0]->cols;
            tab = terms[0]->tab;
        }
        else
        {
            rows = -1;
            cols = 0;
            
            for(auto t: terms)
            {
                rows += t->rows + 1;
                cols = max(cols, t->cols + 6);
            }
            resize();
            
            int h = rows - terms.back()->rows + 1;
            fill_ver(1, h, 0, '|');
            fill_ver(1, h, cols - 1, '|');
            int p = 0;
            for(auto t: terms)
            {
                fill_hor(p + 1, 0, cols - 1, '-');
                tab[p+1][0] = '+';
                tab[p+1][2] = '>';
                tab[p+1][cols - 2] = '>';
                tab[p+1][cols - 1] = '+';
                insert(t, p, 3);
                p += t->rows + 1;
            }
        }
        fprintf(stderr, "done expr\n");
    }
};

struct text : atom
{
    string s;
    
    void read(bool one = false)
    {
        while(ptr >= str && *ptr >= 'A' && *ptr <= 'Z')
        {
            s += *(ptr--);
            if(one) break;
        }
        reverse(s.begin(), s.end());
    }
    
    void init()
    {
        fprintf(stderr, "init text\n");
        rows = 3;
        cols = s.size() + 4;
        resize();
        fill_hor(0, 1, cols - 1, '-');
        fill_hor(rows - 1, 1, cols - 1, '-');
        fill_ver(0, rows - 1, 0, '+');
        fill_ver(0, rows - 1, cols - 1, '+');
        for(int i = 0; i < s.size(); i++)
            tab[1][i + 2] = s[i];
        fprintf(stderr, "done text\n");
    }
};

struct aplus : atom
{
    atom *a;
    
    void read(bool one = false)
    {
        assert(*ptr == '+');
        ptr--;
        a = read_atom(true);
    }
    
    void init()
    {
        fprintf(stderr, "init aplus\n");
        a->init();
        rows = a->rows + 2;
        cols = a->cols + 6;
        resize();
        
        rect(1, rows - 1, 0, cols - 1);
        tab[1][2] = tab[1][cols-2] = '>';
        tab[rows-1][1] = '<';
        insert(a, 0, 3);
        fprintf(stderr, "done aplus\n");
    }
};

struct aquest : atom
{
    atom *a;
    
    void read(bool one = false)
    {
        assert(*ptr == '?');
        ptr--;
        a = read_atom(true);
    }
    
    void init()
    {
        fprintf(stderr, "init aquest\n");
        a->init();
        rows = a->rows + 3;
        cols = a->cols + 6;
        resize();
        
        rect(1, 4, 0, cols - 1);
        tab[4][2] = tab[4][cols-2] = tab[1][cols-2] = '>';
        insert(a, 3, 3);
        fprintf(stderr, "done aquest\n");
    }
};

struct astar : atom
{
    atom *a;
    
    void read(bool one = false)
    {
        assert(*ptr == '*');
        ptr--;
        a = read_atom(true);
    }
    
    void init()
    {
        fprintf(stderr, "init astar\n");
        a->init();
        rows = a->rows + 5;
        cols = a->cols + 6;
        resize();
        
        rect(1, rows - 1, 0, cols - 1);
        tab[1][cols-2] = tab[4][2] = tab[4][cols-2] = '>';
        tab[4][1] = tab[4][cols-3] = '-';
        tab[4][0] = tab[4][cols-1] = '+';
        tab[rows-1][1] = '<';
        insert(a, 3, 3);
        fprintf(stderr, "done astar\n");
    }
};

struct prog : atom
{
    expr *e;
    
    void read(bool one = false)
    {
        e = new expr();
        e->read();
    }
    
    void init()
    {
        fprintf(stderr, "init aprog\n");
        e->init();
        rows = e->rows;
        cols = e->cols + 6;
        resize();
        insert("S->", 1, 0);
        insert("->F", 1, cols - 3);
        insert(e, 0, 3);
    }
};

atom *read_atom(bool one)
{
    assert(ptr >= str);
    fprintf(stderr, "read_atom(%d, %s)\n", ptr - str, ptr);
    atom *a;
    switch(*ptr)
    {
        case '+':
            a = new aplus();
            a->read();
            break;
        case '?':
            a = new aquest();
            a->read();
            break;
        case '*':
            a = new astar();
            a->read();
            break;
        case ')':
            ptr--;
            a = new expr();
            a->read();
            assert(*ptr == '(');
            ptr--;
            break;
        default:
            assert(*ptr >= 'A' && *ptr <= 'Z');
            a = new text();
            a->read(one);
            break;
    };
    fprintf(stderr, "done %s\n", ptr < str ? "ALL" : ptr);
    return a;
}

int main()
{
    scanf("%s", str);
    ptr = str;
    while(*(ptr + 1) != 0)
        ptr++;
    prog p;
    p.read();
    fprintf(stderr, "reading done\n");
    p.init();
    printf("%d %d\n", p.rows, p.cols);
    for(auto row: p.tab){
        for(auto x: row)
            putchar(x);
        puts("");
        }

}