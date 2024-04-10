var a:array[1..100]of longint;
    n,m,i:longint;
begin
 readln(n);
 for i:=1 to n do
 begin
  read(m);
  a[m]:=i;
 end;
 for i:=1 to n do
  write(a[i],' ');
end.