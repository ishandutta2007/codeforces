var a,d,s,t:extended;
    n,i:longint;
begin
 read (a,d);
 read (n);
 s:=0;
 for i:=1 to n do
        begin
         s:=s+d;
         t:=s-trunc(s/(4*a))*(4*a);
         if t<=a then writeln (t:0:6,' ',0);
         if (a<t) and (t<=2*a) then writeln (a:0:6,' ',t-a:0:6);
         if (2*a<t) and (t<=3*a) then writeln (3*a-t:0:6,' ',a:0:6);
         if (3*a<t) and (t<4*a) then writeln (0,' ',4*a-t:0:6);
        end;
end.