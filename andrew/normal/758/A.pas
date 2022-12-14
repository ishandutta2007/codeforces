var
 a:array[1..100000]of longint;
 b,c,i,j,n,max,sc:longint;
begin
 readln(n);
 max:=-maxlongint;
 for i:=1 to n do begin read(a[i]); if a[i]>max then max:=a[i]; end;
 for i:=1 to n do sc:=sc+max-a[i];
 writeln(sc);
end.