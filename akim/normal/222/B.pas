var a,b:array[1..1100]of longint;
    c:array[1..1100,1..1100]of longint;
    n,m,k,i,f,x,y,z:longint;
    q:char;
begin
 readln(n,m,k);
 for i:=1 to n do
  a[i]:=i;
 for i:=1 to m do
  b[i]:=i;
 for i:=1 to n do
  for f:=1 to m do
   read(c[i,f]);
 readln;
 for i:=1 to k do
 begin
  readln(q,x,y);
  case q of
  'g':writeln(c[a[x],b[y]]);
  'c':begin z:=b[x];b[x]:=b[y];b[y]:=z;end;
  'r':begin z:=a[x];a[x]:=a[y];a[y]:=z;end;
  end;
 end;
end.