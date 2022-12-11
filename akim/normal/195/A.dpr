var a,b,c:longint;
begin
 readln(a,b,c);
 if (c*a)mod b=0 then writeln((c*a)div b-c)else writeln((c*a)div b-c+1);
end.