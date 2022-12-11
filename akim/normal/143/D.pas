var a,b,c,s:longint;
begin
 readln(a,b);
 if a=1 then begin writeln(b);halt(0);end;
 if b=1 then begin writeln(a);halt(0);end;
 if a=2 then begin
              s:=0;
              for c:=1 to b do
               if (c mod 4=1)or(c mod 4=2) then inc(s,2);
              writeln(s);
              halt(0);
             end;
 if b=2 then begin
              s:=0;
              for c:=1 to a do
               if (c mod 4=1)or(c mod 4=2) then inc(s,2);
              writeln(s);
              halt(0);
             end;
 if (a*b)mod 2=1 then writeln((a*b)div 2+1) else writeln((a*b)div 2);
end.