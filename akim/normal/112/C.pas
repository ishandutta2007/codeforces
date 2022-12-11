var a,b,c:int64;i:longint;
begin
 readln(a,b,c);
 if c-a<0 then begin writeln('-1');halt(0);end;
 if sqr(c-a+1)+a-1<b then begin writeln('-1');halt(0);end;
 writeln(c-a+1);
 for i:=2 to a do
  writeln(1);
end.