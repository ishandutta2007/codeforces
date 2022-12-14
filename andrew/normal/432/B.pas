var
 cl,s1,s2,x,a,b,home,away,home1,away1:array[1..1000000] of longint;
 l,n,i,j,k,s:longint;
begin
 readln(n);

 for i:=1 to n do
 begin
  readln(a[i],b[i]);
  l:=a[i];
  inc (cl[l]);
 end;
  s:=(n-1)*2;
 for i:=1 to n do
 begin
  l:=b[i];
  s1[i]:=(n-1)+(cl[l]);
  s2[i]:=s-s1[i];
  writeln(s1[i],' ',s2[i]);
 enD;
 writeln;
 readln;
end.