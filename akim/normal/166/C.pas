var a,b,c,n,k,l,i:longint;
begin
 readln(n,k);
 for i:=1 to n do
 begin
  read(l);
  if l>k then inc(a);
  if l=k then inc(b);
  if l<k then inc(c);
 end;
 if ((a+b+c+1)div 2<=b+c)and((a+b+c+1)div 2>c) then begin writeln(0);halt(0);end;
 if a>c then begin a:=a-c;c:=0;end else begin c:=c-a;a:=0;end;
 if a=0 then
 begin
  writeln(c-b+1);
 end else
 if c=0 then
 begin
  writeln(a-b);
 end;
end.