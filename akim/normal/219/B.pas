var a,b,c,l:int64;
begin
 readln(a,b);c:=a;
 l:=1;
 while b>=0 do
 begin
  while (a div l mod 10<>9)and(b>=0) do
  begin
   a:=a-l;
   b:=b-l;
  end;
  if b<0 then begin writeln(c);halt(0);end else begin l:=l*10;c:=a;end;
 end;
end.