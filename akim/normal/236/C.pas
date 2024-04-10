var a:int64;
begin
 readln(a);
 case a of
 1:writeln(1);
 2:writeln(2);
 3:writeln(6);
 4:writeln(12);
 5:writeln(60);
 6:writeln(60);
 else
  begin
   if a mod 2=0 then
   begin
    if a mod 6=0 then writeln((a-1)*(a-2)*(a-3)) else writeln((a)*(a-1)*(a-3));
   end else
    writeln((a)*(a-1)*(a-2));
  end;
 end;
end.