var
 c:char;
 n,i:longint;
begin
 i:=8;
 read(c);
 read(n);
 if ((c='a')or(c='h'))and((n=1)or(n=8)) then dec(i,5)
 else
 begin
  if (c='a')or(c='h') then dec(i,3);
  if (n=1)or(n=8) then dec(i,3);
 end;
 writeln(i);
end.