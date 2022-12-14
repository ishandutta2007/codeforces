const
 d:array[1..12]of longint=(31,28,31,30,31,30,31,31,30,31,30,31);
var
 a,b,l,sc,i,n:longint;
begin
 readln(a,b);
 n:=b-1;
 for i:=1 to d[a] do
 begin
  inc(n);
  if n>7 then begin n:=1; inc(sc); end;
 end;
 writeln(sc+1);
end.