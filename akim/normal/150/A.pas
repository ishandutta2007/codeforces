var a,b,s:int64;i,p:longint;x:array[1..2]of longint;
begin
 readln(a);
 s:=2;b:=trunc(sqrt(a));p:=0;
 while (s<=b) do
  if a mod s=0 then begin a:=a div s;b:=trunc(sqrt(a));inc(p);x[p]:=s;if p=2 then begin writeln('1');writeln(int64(x[1])*x[2]);halt(0);end;end else inc(s);
 if p=1 then writeln('2') else begin writeln('1');writeln('0');end;
end.