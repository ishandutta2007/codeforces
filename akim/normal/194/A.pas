var a,b,c,d:longint;
begin
 readln(a,b);
 if b div a>3 then begin writeln(0);halt(0);end;
 c:=3*a;d:=0;
 while c>b do
 begin
  inc(d);
  c:=c-1;
 end;
 writeln(d);
end.