var n,m,k,s1,s2:longint;
begin
 readln(n,m,k);dec(n);
 if (k=0)and(n=m)and(m>0) then begin writeln('-1');halt(0);end;
 s1:=1;
 if (k=0)and(n>0) then begin dec(n);write(s1,' ');end;
 s2:=s1;
 write(s1,' ');
 while k>0 do
 begin
  dec(k);
  dec(n);
  write(s2+1,' ');
  s1:=s2+1;
  s2:=s2+s1;
 end;
 while m>0 do
 begin
  dec(m);
  dec(n);
  write(s1+1,' ');
  s1:=s1+1;
 end;
 while n>0 do
 begin
  dec(n);
  write(s1,' ');
 end;
end.