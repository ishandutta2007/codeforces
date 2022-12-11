var a,b,c:array[1..52,1..52]of int64;
    n,o:int64;m,k,i,f,g:longint;s:string;
function obr(c:char):longint;
begin
 case c of
 'a':obr:=1;'b':obr:=2;'c':obr:=3;'d':obr:=4;'e':obr:=5;'f':obr:=6;'g':obr:=7;'h':obr:=8;'i':obr:=9;'j':obr:=10;
 'k':obr:=11;'l':obr:=12;'m':obr:=13;'n':obr:=14;'o':obr:=15;'p':obr:=16;'q':obr:=17;'r':obr:=18;'s':obr:=19;'t':obr:=20;
 'u':obr:=21;'v':obr:=22;'w':obr:=23;'x':obr:=24;'y':obr:=25;'z':obr:=26;'A':obr:=27;'B':obr:=28;'C':obr:=29;'D':obr:=30;
 'E':obr:=31;'F':obr:=32;'G':obr:=33;'H':obr:=34;'I':obr:=35;'J':obr:=36;'K':obr:=37;'L':obr:=38;'M':obr:=39;'N':obr:=40;
 'O':obr:=41;'P':obr:=42;'Q':obr:=43;'R':obr:=44;'S':obr:=45;'T':obr:=46;'U':obr:=47;'V':obr:=48;'W':obr:=49;'X':obr:=50;
 'Y':obr:=51;'Z':obr:=52;
 end;
end;
begin
 readln(n,m,k);
 for i:=1 to m do
  for f:=1 to m do
   a[i,f]:=1;
 if n=1 then begin writeln(m);halt(0);end else n:=n-2;
 for i:=1 to k do
 begin
  readln(s);
  a[obr(s[1]),obr(s[2])]:=0;
 end;
  b:=a;
 while n>0 do
 begin
  if n mod 2=1 then 
  begin
   for i:=1 to m do
    for f:=1 to m do
    begin
     c[i,f]:=0;
     for g:=1 to m do
      c[i,f]:=(c[i,f]+(a[i,g]*b[g,f]) mod 1000000007)mod 1000000007;
    end;
   a:=c;
  end;
  for i:=1 to m do
   for f:=1 to m do
   begin
    c[i,f]:=0;
    for g:=1 to m do
     c[i,f]:=(c[i,f]+(b[i,g]*b[g,f]) mod 1000000007)mod 1000000007;
   end;
  b:=c;
  n:=n div 2;
 end;
 o:=0;
 for i:=1 to m do
  for f:=1 to m do
   o:=(o+a[i,f])mod 1000000007;
 writeln(o);
end.