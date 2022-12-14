var
 a:array[1..1000] of longint;
 n,i,sc,k:longint;
begin
 readln(n,k);
 for i:=1 to n do read(a[i]);
 for i:=1 to n do if a[i]>0 then if a[i]>=a[k] then inc(sc);
 writeln(sc);
end.