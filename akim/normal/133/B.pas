var t:string;s,h,l,i:longint;
begin
 readln(t);
 l:=length(t);
 h:=1;s:=0;
 for i:=l downto 1 do
 begin
  case t[i] of 
  '>':begin h:=(h*2)mod 1000003;h:=(h*2)mod 1000003;h:=(h*2)mod 1000003;s:=(s+h)mod 1000003;h:=(h*2)mod 1000003;end;
  '<':begin s:=(s+h)mod 1000003;h:=(h*2)mod 1000003;h:=(h*2)mod 1000003;h:=(h*2)mod 1000003;s:=(s+h)mod 1000003;h:=(h*2)mod 1000003;end;
  '+':begin h:=(h*2)mod 1000003;s:=(s+h)mod 1000003;h:=(h*2)mod 1000003;h:=(h*2)mod 1000003;s:=(s+h)mod 1000003;h:=(h*2)mod 1000003;end;
  '-':begin s:=(s+h)mod 1000003;h:=(h*2)mod 1000003;s:=(s+h)mod 1000003;h:=(h*2)mod 1000003;h:=(h*2)mod 1000003;s:=(s+h)mod 1000003;h:=(h*2)mod 1000003;end;
  '.':begin h:=(h*2)mod 1000003;h:=(h*2)mod 1000003;s:=(s+h)mod 1000003;h:=(h*2)mod 1000003;s:=(s+h)mod 1000003;h:=(h*2)mod 1000003;end;
  ',':begin s:=(s+h)mod 1000003;h:=(h*2)mod 1000003;h:=(h*2)mod 1000003;s:=(s+h)mod 1000003;h:=(h*2)mod 1000003;s:=(s+h)mod 1000003;h:=(h*2)mod 1000003;end;
  '[':begin h:=(h*2)mod 1000003;s:=(s+h)mod 1000003;h:=(h*2)mod 1000003;s:=(s+h)mod 1000003;h:=(h*2)mod 1000003;s:=(s+h)mod 1000003;h:=(h*2)mod 1000003;end;
  ']':begin s:=(s+h)mod 1000003;h:=(h*2)mod 1000003;s:=(s+h)mod 1000003;h:=(h*2)mod 1000003;s:=(s+h)mod 1000003;h:=(h*2)mod 1000003;s:=(s+h)mod 1000003;h:=(h*2)mod 1000003;end;
  end;
 end;
 writeln(s);
end.