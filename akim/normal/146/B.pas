var a,b,x:longint;
    s,t:string;
begin
 readln(a,b);
 str(b,s);
 inc(a);
 while true do
 begin
  t:='';
  x:=a;
  while a<>0 do
  begin
   if a mod 10=4 then t:='4'+t;
   if a mod 10=7 then t:='7'+t;
   a:=a div 10;
  end;
  a:=x;
  if t=s then begin writeln(a);halt(0);end;
  inc(a);
 end;
end.