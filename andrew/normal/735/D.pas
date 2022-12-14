var
 a,b,c,i,j:longint;
function proverka(a:Longint):longint;
var sqx,b,sc,i:Longint;
begin
 proverka:=0;
 sqx:=trunc(sqrt(a));
 for i:=2 to sqx do if a mod i=0 then begin proverka:=1; exit; end;
end;
begin
 readln(a);
 if proverka(a)=0 then begin writeln(1); halt; end;
 if a mod 2=0 then begin writeln(2); halt; end;
 if proverka(a-2)=0 then begin writeln(2); halt; end;
 writeln(3);
end.