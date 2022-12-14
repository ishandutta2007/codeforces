var
 a,b:ansistring;
 sch1,sch2,s,i,k:longint;
begin
 readln(a);
 readln(b);
 for i:=1 to length(a) do
 begin
  sch1:=ord(a[i])-48;
  inc(s,sch1);
 end;
 for i:=1 to length(b) do
 begin
  sch1:=ord(b[i])-48;
  inc(k,sch1);
 end;
 if odd(s) then inc(s);
 if s>=k then writeln('YES') else writeln('NO');
end.